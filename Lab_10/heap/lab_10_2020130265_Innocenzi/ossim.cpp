//--------------------------------------------------------------------
//
//  Laboratory B, In-lab Exercise 1                       ossim.cs
//
//  (Shell) Operating system task scheduling simulation
// 2020130265
//--------------------------------------------------------------------

// Simulates an operating system's use of a priority queue to regulate
// access to a system resource (printer, disk, etc.).

#include <iostream>
#include <cstdlib>
#include <vector>
#include "ptyqueue.cpp"

using namespace std;

//--------------------------------------------------------------------
//
// Declaration for the task data struct
//

struct TaskData
{
    int priority,              // Task's priority
        arrived;               // Time when task was enqueued

    void setPty(int newPty)
        { priority = newPty; }   // Set the priority

    int pty () const
        { return priority; }   // Returns the priority
};

//--------------------------------------------------------------------

int main ()
{
    PtyQueue<TaskData> taskPQ;   // Priority queue of tasks
    TaskData task;               // Task
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        numPtyLevels,            // Number of priority levels
        numArrivals;               // Number of new tasks arriving
    std::vector<int> lowMax;
    std::vector<int> highMax;
    

    cout << endl << "Enter the number of priority levels : ";
    cin >> numPtyLevels;

    cout << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    numArrivals = 0;
    for ( minute = 0 ; minute < simLength ; minute++ )
    {
        std::cout << "Minute " << minute << std::endl;
        // Dequeue the first task in the queue (if any).
        if (!taskPQ.isEmpty()){
            task = taskPQ.dequeue();
            std::cout << "This task was arrived in " << task.arrived << ", and waited for " << minute - task.arrived << "minutes."<< std::endl;
            if (task.pty() == 0)
                lowMax.push_back(minute-task.arrived);
            if (task.pty() == 1)
                highMax.push_back(minute-task.arrived);
        }
            
        
        int k = rand() % 4;
            
        if (k == 1) {
            std::cout << "One task enqueued." << std::endl;
            numArrivals++;
            task.setPty(rand()%numPtyLevels);
            task.arrived = minute;
            taskPQ.enqueue(task);
            
        }
        else if (k == 2) {
            std::cout << "Two task enqueued." << std::endl;
            task.arrived = minute;
            numArrivals++;
            task.setPty(rand()%numPtyLevels);
            taskPQ.enqueue(task);
            numArrivals++;
            task.setPty(rand()%numPtyLevels);
            taskPQ.enqueue(task);
        }
        else{
            std::cout << "No task enqueued." << std::endl;
        }
        taskPQ.showStructure();
    }
    auto max_low = max_element(std::begin(lowMax), std::end(lowMax));
    auto max_high = max_element(std::begin(highMax), std::end(highMax));
    std::cout << "Longest wait for any low-priority(0) task: " << *max_low << std::endl;
    std::cout << "Longest wait for any high-priority(1) task: " << *max_high << std::endl;
    //system("pause")
    return(0);
}
