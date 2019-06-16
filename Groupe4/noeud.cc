#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

/**
 * Let us take a step back, and remove random delaying from the code.
 * We'll leave in, however, losing the packet with a small probability.
 * And, we'll we do something very common in telecommunication networks:
 * if the packet doesn't arrive within a certain period, we'll assume it
 * was lost and create another one. The timeout will be handled using
 * (what else?) a self-message.
 */
class Tic8 : public cSimpleModule
{
  private:
    simtime_t timeout;  // timeout
    cMessage *timeoutEvent;  // holds pointer to the timeout self-message

  public:
    Tic8();
    virtual ~Tic8();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Tic8);

Tic8::Tic8()
{
    timeoutEvent = nullptr;
}

Tic8::~Tic8()
{
    cancelAndDelete(timeoutEvent);
}

void Tic8::initialize()
{
    // Initialize variables.
    timeout = 5;
    timeoutEvent = new cMessage("Ceci vient de  ordi1");

    // Generate and send initial message.
    EV << "Initialisation du message\n";
    cMessage *msg = new cMessage("Message de ordinateur 1");
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Tic8::handleMessage(cMessage *msg)
{
    if (msg == timeoutEvent) {
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        EV << "Temps depasse  \n";
        cMessage *newMsg = new cMessage("Ceci vient de  ordi1");
        send(newMsg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
}

/**
 * Sends back an acknowledgement -- or not.
 */
class Toc8 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Toc8);

void Toc8::handleMessage(cMessage *msg)
{
    if (uniform(0, 1) < 4) {
        EV << "A message.\n";
        bubble("message recu");  // making animation more informative...
        delete msg;
    }

}
