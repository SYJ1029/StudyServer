#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>

void HelloThread() {

    cout << "Hello Thread :)" << endl;
}

int main()
{
    HelloWorld();

    std::thread t;

    auto id1 = t.get_id();
    cout << id1 << endl;


    t = std::thread(HelloThread);
    auto id2 = t.get_id();
    cout << id2 << endl;

    int64 cnt = t.hardware_concurrency();

    cout << cnt << endl;

    cout << "Hello Main :(" << endl;


    t.join();
}

