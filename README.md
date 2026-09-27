# Simple_cpp-inventory-billing-system
Console-based C++ inventory and billing system with basket management, invoice generation, file handling, and date/time functionality. 


# C++ Inventory and Billing System

A console-based inventory and billing system developed as an independent C++ programming project.

## Features

* Displays available products and their prices
* Adds items and quantities to a basket
* Allows items to be removed from the basket
* Displays the current basket
* Calculates the total bill
* Generates a formatted invoice in the console
* Generates a text-based invoice using file handling
* Includes the current date on invoices

## C++ Concepts Used

* Classes and objects
* Encapsulation using private data members
* Constructors
* Member functions
* Arrays of objects
* Functions and parameters
* Loops and conditional statements
* Input/output handling
* File handling with `ofstream`
* Date and time functions
* Output formatting with `iomanip`

## How It Works

The program maintains a list of products using objects of the `item` class. Each item stores its name, item code, price, and quantity currently in the basket.

The user can add or discard quantities using the item code, view the basket, calculate the grand total, and generate an invoice.

The invoice can either be displayed directly in the console or written to a text file.

## Purpose

This project was created to practice applying C++ concepts in a larger program rather than isolated exercises. It builds on earlier projects such as a calculator and a Tic-Tac-Toe game.

## Future Improvements

Possible future improvements include:

* Input validation for invalid menu choices
* Persistent storage of inventory data
* Support for a larger product catalogue
* More detailed invoice information
* Improved formatting of the generated invoice
