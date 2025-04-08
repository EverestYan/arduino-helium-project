# data_analysis.py
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy as np

# 分析空气实验数据
air_data = pd.read_csv('air_data.csv', names=['time_ms', 'distance_cm'])
plt.figure()
plt.plot(air_data['time_ms'], air_data['distance_cm'], 'b-', label='Raw Data')
plt.xlabel('Time (ms)')
plt.ylabel('Distance (cm)')

# 添加最佳拟合线（假设匀速运动）
def linear_fit(x, a, b):
    return a * x + b
params, _ = curve_fit(linear_fit, air_data['time_ms'], air_data['distance_cm'])
plt.plot(air_data['time_ms'], linear_fit(air_data['time_ms'], *params), 'r--', 
         label=f'Fit: v={params[0]:.2f} cm/ms')
plt.legend()
plt.savefig('air_velocity.png')

# 分析氦气实验数据
helium_data = pd.read_csv('helium_data.csv', names=['concentration', 'speed_mps'])
plt.figure()
plt.errorbar(helium_data['concentration'], helium_data['speed_mps'], 
             yerr=helium_data['speed_mps'].std(), fmt='o', capsize=5)
plt.xlabel('Helium Concentration (%)')
plt.ylabel('Sound Speed (m/s)')
plt.savefig('helium_speed.png')

# 噪声分析示例（FFT）
from scipy.fft import fft
yf = fft(air_data['distance_cm'].values)
xf = np.fft.fftfreq(len(yf), 0.1)  # 0.1s 采样间隔
plt.figure()
plt.plot(xf, np.abs(yf))
plt.xlabel('Frequency (Hz)')
plt.ylabel('Amplitude')
plt.xlim(0, 10)  # 查看低频噪声
plt.savefig('noise_spectrum.png')