Banking System in C++

onlineGDB = https://onlinegdb.com/Uvo2rvefn

A simple console-based Banking Management System developed in C++ using Object-Oriented Programming (OOP) concepts like:

Inheritance
Polymorphism
Abstraction
Virtual Functions
Dynamic Memory Allocation

This project allows users to create different bank account types and perform banking operations such as deposit, withdrawal, displaying account details, and interest calculation.

Features

Account Types
Savings Account
Current (Checking) Account
Fixed Deposit Account
Banking Operations
Create Account
Deposit Money
Withdraw Money
Display Account Information
Calculate Interest
Overdraft Facility for Current Account
OOP Concepts Used
Concept	Usage
Inheritance	Different account types inherit from BankAccount
Polymorphism	calculateInterest() and withdraw() are overridden
Abstraction	Pure virtual function used in base class
Encapsulation	Balance kept private
Dynamic Binding	Runtime polymorphism using pointers
Technologies Used
Language: C++

STL: vector
Project Structure
BankingSystem.cpp
README.md
Class Diagram Overview
Base Class
class BankAccount
Derived Classes
class SavingsAccount : public BankAccount
class CheckingAccount : public BankAccount
class FixedDepositAccount : public BankAccount


Menu Options
1. Create Savings Account
2. Create Current Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
8. Exit

Example Output
-- BANKING SYSTEM --
1. Create Savings Account
2. Create Current Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest
8. Exit

Enter Your Choice : 1

Enter Account No :
101

Enter Holder Name :
Ruchit

Enter Balance :
5000

Enter Interest Rate :
5

Savings Account Created Successfully
Interest Calculation
Savings Account

Interest is calculated based on user-defined interest rate.

Fixed Deposit Account

Fixed interest rate:

7% annually
Current Account

No interest is provided.

Memory Management

Dynamic memory is allocated using:

new

Released using:

delete

This prevents memory leaks.

Future Improvements
File Handling
Account Search by Number
Login System
Transaction History
Database Integration
GUI Interface
Online Banking Features
Author

Ruchit
