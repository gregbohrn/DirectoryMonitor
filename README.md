# Directory Monitor in C++

## Overview

This project implements a directory monitoring system in C++ using the Observer design pattern. The system monitors a specified directory for file changes (additions and deletions) and notifies registered consumers (observers) of these changes. The key components of the design include an `IObserver` interface, a `DirectoryNotifier` class, and a concrete observer implementation (`ConsoleLogger`).

## Design

### 1. Observer Interface (`IObserver`)

The `IObserver` interface defines the contract for any observer that wants to receive notifications about file changes in the monitored directory. It includes two pure virtual methods:

- `void OnFileAdded(const string& filename)`: Called when a new file is added to the directory.
- `void OnFileRemoved(const string& filename)`: Called when a file is removed from the directory.

### 2. Monitor Class (`DirectoryWatcher`)

The `DirectoryWatcher` class is responsible for:

- Monitoring the specified directory for any file changes.
- Maintaining a list of subscribed observers.
- Notifying observers when a file is added or removed.

#### Key Methods:

- `DirectoryWatcher(const string& directoryPath)`: Constructor that initializes the notifier with the directory path to monitor.
- `void Subscribe(IObserver* observer)`: Allows an observer to subscribe to change events.
- `void Unsubscribe(IObserver* observer)`: Allows an observer to unsubscribe from change events.
- `void StartMonitoring(int pollIntervalMs = 1000)`: Starts monitoring the directory, polling for changes at a specified interval (default is 1000ms).
- `void StopMonitoring()`: Stops the monitoring process.

#### Internal Methods:

- `set<string> DirectoryFileList()`: Lists all files in the monitored directory.
- `void NotifyFileAdded(const string& filename)`: Notifies all subscribed observers that a file has been added.
- `void NotifyFileRemoved(const string& filename)`: Notifies all subscribed observers that a file has been removed.

### 3. Concrete Observer (`ConsoleLogger`)

The `ConsoleLogger` class implements the `IObserver` interface. It logs file additions and removals to the console.

#### Methods:

- `void OnFileAdded(const string& filename) override`: Logs a message to the console when a file is added.
- `void OnFileRemoved(const string& filename) override`: Logs a message to the console when a file is removed.

## Usage

### 1. Compilation

This was compiled on Visual Studio 2022 and tested in Debug x64 mode.  C++ 17 was used for the build to get access to std::filesystem.

### 2. Notes
Unit Testing can be added via gtest, CppTest, Boost.Test or other Testing system of choice.  I prefer the first 2.
This is a simple file monitor.  We could get more complicated with event monitoring, etc.  This should be compilable across OS but I have not tested.