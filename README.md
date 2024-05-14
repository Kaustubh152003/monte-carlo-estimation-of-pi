# Monte Carlo Estimation of Pi

Estimating the value of pi through randomness.

## Overview

This project demonstrates a simple Monte Carlo method for estimating the value of pi. The Monte Carlo method is a statistical technique that uses random sampling to obtain numerical results. In this case, we utilize the randomness to estimate the value of pi.

## How It Works

1. **Generate Random Points**: Random points are generated within a square area.
2. **Check if Inside the Circle**: For each point, we check if it falls inside the inscribed circle within the square.
3. **Calculate Pi Approximation**: By comparing the number of points inside the circle to the total number of points generated, we approximate the value of pi.

## Usage

To run the estimation:

```bash
g++ get_pi.cpp
./a.out
