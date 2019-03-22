# Bank Account Simulation
Implement functionality to accrue interest for an investment account.

## Introduction
- For a real bank, there are many aspects to this calculation, but for the purposes of this project, we will keep things short and simple. 
  - Our bank will assume interest is accrued monthly, not daily, and the length of the month will not affect the amount of interest - that is: every month will accrue “one month’s worth of interest”, whether the month has 28 days or 31 days, etc.
  
  - For the investment account we’re considering, additional deposits or withdrawals are not allowed, so balance cannot change in any way, except for accrual of interest - that is: our accrual approach can use the account balance for the month without concern for the balance changing mid-month due to other withdrawals or deposits.
  
  - Our bank has three different interest rates, depending on the balance of the customer’s account. Higher balances will get a higher rate in order to persuade customers to have a larger balance. The interest rates work as follows:
    - Customer balances under $1000.00 (exclusive) will be given a monthly interest rate of 0.15%, which our bank calls the “minimum interest rate”.
    - Customer balances over $15000.00 (inclusive) will be given a monthly interest rate of 0.4%, which our bank calls the “maximum interest rate”.
    - Other balances (i.e. between $1000.00 (inclusive) and $15000.00 (exclusive)) will be given a monthly interest rate of 0.225%, which our bank calls the “standard interest rate” since the majority of our customer’s balances are within this range.
    - Interest is accrued once per month and is calculated simply by multiplying the month’s balance by the appropriate monthly interest rate and adding the result back to the balance. Only one interest rate is used during a month - that is, if a balance is increased to the next-level interest rate during a month, the new rate is not utilized until the next month.
