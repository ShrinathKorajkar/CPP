/*
    Command Pattern:  ->  Encapsulates a request as an object, thereby allowing for parameterization
    of clients with queues, requests, and operations.

    The request object can be used to store, queue, undo/redo, log
    encapsulate action + receiver of the action => command
    Instead of calling function directly -> wrap the fun call into a command object
    decouple obj that issue req from obj that perform req

    Application - undo/redo, queue or schedule operations, GUI -> each button is command
    You want to issue requests, but you don’t want callers to know HOW they are executed
*/
#include <iostream>
#include <memory>

// Receiver -> actual doing work
class Light
{
public:
    void on() { std::cout << "Light ON\n"; }
    void off() { std::cout << "Light OFF\n"; }
};

class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0; // optional
    virtual ~Command() = default;
};

class LightOnCommand : public Command
{
    Light &light;

public:
    LightOnCommand(Light &l) : light(l) {}

    void execute() override { light.on(); }
    void undo() override { light.off(); }
};

class LightOffCommand : public Command
{
    Light &light;

public:
    LightOffCommand(Light &l) : light(l) {}

    void execute() override { light.off(); }
    void undo() override { light.on(); }
};

// Invoker
class RemoteControl
{
    std::unique_ptr<Command> command;

public:
    void setCommand(std::unique_ptr<Command> cmd)
    {
        command = std::move(cmd);
    }

    void pressButton()
    {
        if (command)
            command->execute();
    }

    void pressUndo()
    {
        if (command)
            command->undo();
    }
};

int main()
{
    Light livingRoomLight;

    RemoteControl remote;

    remote.setCommand(std::make_unique<LightOnCommand>(livingRoomLight));
    remote.pressButton(); // Light ON
    remote.pressUndo();   // Light OFF

    remote.setCommand(std::make_unique<LightOffCommand>(livingRoomLight));
    remote.pressButton(); // Light OFF
    remote.pressUndo();   // Light ON
}
