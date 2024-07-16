// Code to take raw IMU data and filter it to compute AHRS 

#include <iostream>
#include <cmath>

// Function to compute the complementary filter
void complementary_filter(const double accel[3], const double gyro[3], const double mag[3], double dt, double alpha,
                          double &pitch, double &roll, double &yaw,
                          double &pitch_gyro, double &roll_gyro, double &yaw_gyro) {
    // Accelerometer angles
    double pitch_acc = std::atan2(accel.y, std::sqrt(accel.x * accel.x + accel.z * accel.z));
    double roll_acc = std::atan2(-accel.x, accel.z);

    // Magnetometer angles (compensated)
    double mag_x_comp = mag.x * std::cos(pitch_acc) + mag.z * std::sin(pitch_acc);
    double mag_y_comp = mag.x * std::sin(roll_acc) * std::sin(pitch_acc) + mag.y * std::cos(roll_acc) - mag.z * std::sin(roll_acc) * std::cos(pitch_acc);
    double yaw_mag = std::atan2(-mag_y_comp, mag_x_comp);

    // Integrate gyroscope data
    pitch_gyro += gyro.x * dt;
    roll_gyro += gyro.y * dt;
    yaw_gyro += gyro.z * dt;

    // Apply complementary filter
    pitch = alpha * pitch_gyro + (1 - alpha) * pitch_acc;
    roll = alpha * roll_gyro + (1 - alpha) * roll_acc;
    yaw = alpha * yaw_gyro + (1 - alpha) * yaw_mag;
}

int main() {
    double dt = 0.01;  // Time step
    double alpha = 0.98;  // Filter coefficient

    // Initialize angles
    double pitch = 0.0, roll = 0.0, yaw = 0.0;
    double pitch_gyro = 0.0, roll_gyro = 0.0, yaw_gyro = 0.0;

    // Simulated sensor data
    double accel[3] = {0.0, 0.0, 1.0};
    double gyro[3] = {0.01, 0.02, 0.03};
    double mag[3] = {0.3, 0.4, 0.5};

    // Run the complementary filter
    complementary_filter(accel, gyro, mag, dt, alpha, pitch, roll, yaw, pitch_gyro, roll_gyro, yaw_gyro);
    std::cout << "Pitch: " << pitch << ", Roll: " << roll << ", Yaw: " << yaw << std::endl;

    return 0;
}

