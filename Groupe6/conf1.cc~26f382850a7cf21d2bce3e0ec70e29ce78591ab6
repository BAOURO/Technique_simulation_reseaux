#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <Message_m.h>

using namespace omnetpp;

class Pc1 : public cSimpleModule
{
  private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent;  // holds pointer to the timeout self-message

  public:
    Pc1();
    virtual ~Pc1();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Pc1);

Pc1::Pc1()
{
    timeoutEvent = nullptr;
}

Pc1::~Pc1()
{
    cancelAndDelete(timeoutEvent);
}

void Pc1::initialize()
{
    // Initialize variables.
    timeout = 5.0;
    timeoutEvent = new cMessage("Timeout");

    // Generate and send initial message.
    EV << "Sending initial message\n";
    Packet *msg = new Packet();
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Pc1::handleMessage(cMessage *msg)
{
    if (msg == timeoutEvent) {
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        EV << "Envoi message\n";
        Packet *newMsg = new Packet();

        send(newMsg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);
    }

}


class Pc2 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Pc2);

void Pc2::handleMessage(cMessage *msg)
{
    if (uniform(0, 1) < 2) {
        EV << "\"Message recu.\n";
        bubble("Arrive");  // making animation more informative...
        delete msg;
    }
    else {
        delete msg;
    }
}
