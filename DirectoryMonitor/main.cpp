// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

// System Includes
#include <iostream>
#include <thread>

// Project Includes
#include "ConsoleLogger.h"
#include "DirectoryWatcher.h"


// //////////////////////////////////////////////////////////////
// Main Entry Point
// //////////////////////////////////////////////////////////////
int main()
{
    // Setup Objects
    DirectoryWatcher notifier("C:/!!Watch");
    ConsoleLogger logger;
    notifier.Subscribe(&logger);

    // Start montiering thread
    std::thread monitorThread([&notifier]()
    {
        notifier.StartMonitoring(1000); // Poll every 1 second
    });

    // Notify and wait
    std::cout << "Press Enter to stop monitoring..." << std::endl;
    std::cin.get();

    // Teardown
    notifier.StopMonitoring();
    monitorThread.join();
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
