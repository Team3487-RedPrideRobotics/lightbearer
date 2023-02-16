// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

package frc.robot.subsystems;

import edu.wpi.first.wpilibj.DriverStation;
import edu.wpi.first.wpilibj.RobotBase;
import edu.wpi.first.wpilibj.RobotController;
import edu.wpi.first.wpilibj.RobotState;
import edu.wpi.first.wpilibj.SerialPort;
import edu.wpi.first.wpilibj.Timer;
import edu.wpi.first.wpilibj.DriverStation.Alliance;
import edu.wpi.first.wpilibj.SerialPort.WriteBufferMode;
import edu.wpi.first.wpilibj.motorcontrol.Spark;
import edu.wpi.first.wpilibj2.command.SubsystemBase;
import frc.robot.Constants;

public class LightSubsystem extends SubsystemBase {
    
    //region pattern constants
    private static final byte[] yellow = new byte[]{0x59};
    private static final byte[] purple = {0x50};
    private static final byte[] red = {0x52};
    private static final byte[] blue = {0x42};
    private static final byte[] idle = {0x49};
    private static final byte[] celebration = {0x43};
    
    //endregion
    
    //region private fields and constructor
    private boolean isPurple;
    private boolean isYellow;
    
    private SerialPort arduino;
  
    public LightSubsystem() {
            arduino = new SerialPort(9600, SerialPort.Port.kUSB1);
            System.out.println("connected on kUSB!");
            arduino.setWriteBufferMode(WriteBufferMode.kFlushOnAccess);

    }
    //endregion
    
    //region subsystem methods
    @Override
    public void periodic() {
        System.out.println(arduino.readString());
        // This method will be called once per scheduler run
        if(RobotState.isDisabled()){
            arduino.write(idle, 1);
        }
    }
    
    @Override
    public void simulationPeriodic() {
        // This method will be called once per scheduler run during simulation
    }
    //endregion
    
    public void togglePurple() {
        //red 0.61
        //blue 0.87
        if (isPurple) {
            isPurple = false;
            isYellow = false;
            arduino.write(getAllianceColor(), 1);
        }
        else {
            isPurple = true;
            isYellow = false;
            arduino.write(purple, 1);
        }
    }
    
    public void toggleYellow() {
        if (isYellow) {
            isYellow = false;
            isPurple = false;
            arduino.write(getAllianceColor(), 1);
        }
        else {
            isYellow = true;
            isPurple = false;
            arduino.write(yellow, 1);
        }
    }
    
    public byte[] getAllianceColor() {
        if (DriverStation.getAlliance() != null) {
            return DriverStation.getAlliance() == Alliance.Red ? red : blue;
        }
        return red;
    }

    public void displayAllianceColor(){
        arduino.write(getAllianceColor(), 1);
    }

    public void writeToArduino(String message){
        arduino.writeString(message);
    }
}
