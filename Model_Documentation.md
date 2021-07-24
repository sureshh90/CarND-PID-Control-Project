# **PID Controller Project**

The goal of this project is to safely navigate around a virtual track using the PID controller.

There are potential shortcomings with the current approach, which are identified, and methods to address them are also elaborated in this document.

[//]: # (Image References)

[image1]: ./writeup_images/p_controller.png "P Controller"
[image2]: ./writeup_images/d_controller_1.png "D Controller Component"
[image3]: ./writeup_images/d_controller_2.png "PD Controller Component"
[image4]: ./writeup_images/i_controller_1.png "I Controller Component"
[image5]: ./writeup_images/i_controller_2.png "PID Controller Component"




## Available Data

The simulator will provide the cross track error (CTE) and the velocity (mph) in order to compute the appropriate steering angle.


## Theoritical Background

Let us have a brief overview of the theory behind the PID controller before going into the details of implementation.

PID stands for Proportional-Integral-Derivative and each component introduces a value that tries to reduce the total error.

### P Controller:

The P component tries to reduce the total error by introducing a component which is directly proportional to the error observed. 

The P component is defined as 

```-Kp * CTE```

The characteristic of P controller is shown in the figure below [1].

![alt text][image1]


It can be noted in the figure, the error is reduced such that it oscillates around the zero error.


### D Controller:

The D component tries to reduce the total error by introducing a component which is directly proportional to the derivative of the error function (i.e. the difference between current and previous error value). 

The D component is defined as 

```-Kd * (CURRENT_CTE - PREV_CTE)```

The characteristic of D controller is shown in the figure below [1].

![alt text][image2]


The characteristic of PD controller is shown in the figure below [1].

![alt text][image3]


It can be noted in the first figure, the value decreases after the initial high because the error difference keeps decreasing. 

On combining both the components it can been seen that the error is reduced such that it converges to zero error after a certain time period.



### I Controller:

The I component tries to reduce the total error by introducing a component which is directly proportional to the integral of the error function (i.e. the accumulated error until the particular time point). 

The I component is defined as 

```-Ki * (ACCUMULATED_CTE)```

The characteristic of I controller is shown in the figure below [1].

![alt text][image4]


The characteristic of PID controller is shown in the figure below [1].

![alt text][image5]

It can be noted in the figure, the error is reduced such that it  overshoots initially and then converges to the zero error after a certain time period.

The integral component is effective in reducing long standing errors like steering drift, etc.

## Implementation of the project

In our project, we have used PID Controller is used to steer the vehicle through the virtual track. 

Here in our case, the Cross Track Error (CTE) is given by the simulator and our aim to reduce this error to minimum. 

The classes are implemented and the now the parameters Kp, Kd and Ki have to be tuned. In this project, the parameters have been tuned manually. 

Initially we begin by setting the parameters to [Kp, Kd, Ki] = [0.005, 0, 0]. Since only the P component is active now, it can been seen that the vehicle oscillates between the track (sometimes going out of track.). On increasing the Kp = 0.05, we could see a better performance in driving the vehicle.

In order to prevent the oscillations, the D component is introduced by setting the value of Kd  to 1. This reduced the oscillation amplitude and therefore it was increased further to around 2. This provided a better performance.


The next component which is I component is not used in this project since it provides a big overshoot in the beginning which is undesirable. The advantages of I component are only visible when we have a systematic error introduced in our project due to external factors like steering drift (which in our simulation project should be zero.).


On finetuning the parameters, the values of [Kp, Kd, Ki] = [0.075, 2.1, 0] have been finalized and provides a good performance in driving the car around the track.


### Shortcoming identified and possible improvements to the project

* As already discussed, the tuning of parameters are manual and therefore there is room for improvement in hyperparameter tuning.

* The hyperparameter tuning could be automated by using algorithms like Twiddle, SGD, etc, which will provide the optimal parameters for the current track.

* The speed of the vehicle can be improved by establishing a relation between steering and throttle and by tuning the corresponding hyperparameters.


### References:

[1] Udacity Coursework.