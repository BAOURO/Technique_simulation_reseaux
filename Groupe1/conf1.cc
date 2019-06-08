#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <Message_m.h>

using namespace omnetpp;

class Ordi1 : public cSimpleModule
{
  private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent;  // holds pointer to the timeout self-message

  public:
    Ordi1();
    virtual ~Ordi1();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi1);

Ordi1::Ordi1()
{
    timeoutEvent = nullptr;
}

Ordi1::~Ordi1()
{
    cancelAndDelete(timeoutEvent);
}

void Ordi1::initialize()
{
    // Initialize variables.
    timeout = 5.0;
    timeoutEvent = new cMessage("Timeout");

    // Generate and send initial message.
    EV << "Sending initial message\n";
    Message *msg = new Message();
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Ordi1::handleMessage(cMessage *msg)
{
    if (msg == timeoutEvent) {
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        EV << "Sending message\n";
        Message *newMsg = new Message();

        send(newMsg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);
    }

}


class Ordi2 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi2);

void Ordi2::handleMessage(cMessage *msg)
{
    if (uniform(0, 1) < 2) {
        EV << "\"Message received.\n";
        bubble("Received");  // making animation more informative...
        delete msg;
    }
    else {
        delete msg;
    }
}
