<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <fstream>


#include "message_m.h"

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
    virtual Message *generateMessage();
    virtual void envoiMessage(Message *msg);
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
    timeoutEvent = new cMessage("delai depasse");
    // Generate and send initial message.
    EV << "Sending initial message\n";
    cMessage *msg = new cMessage("ceci vient de Ordi1 ");
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}
void Ordi1::handleMessage(cMessage *msg)
{
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        Message *newmsg = generateMessage();
        EV << newmsg << "\n";
        envoiMessage(newmsg);
        scheduleAt(simTime()+timeout, timeoutEvent);
}

Message *Ordi1::generateMessage()
{
    char msgname[20];
    sprintf(msgname, " ceci vient de Ordi1");
    // Create message object and set source and destination field.
    Message *msg = new Message(msgname);
    return msg;
}

void Ordi1::envoiMessage(Message *msg)
{
    // Increment hop count.
    send(msg, "out");
}

class Ordi2 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi2);
void Ordi2::handleMessage(cMessage *msg)
{
        EV << "Message recu ordi2 \n";
        bubble("message accepte");  // making animation more informative...
        delete msg;
}
=======
#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <iostream>
#include <fstream>


#include "message_m.h"

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
    virtual Message *generateMessage();
    virtual void envoiMessage(Message *msg);
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
    timeoutEvent = new cMessage("delai depasse");
    // Generate and send initial message.
    EV << "Sending initial message\n";
    cMessage *msg = new cMessage("ceci vient de Ordi1 ");
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}
void Ordi1::handleMessage(cMessage *msg)
{
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        Message *newmsg = generateMessage();
        EV << newmsg << "\n";
        envoiMessage(newmsg);
        scheduleAt(simTime()+timeout, timeoutEvent);
}

Message *Ordi1::generateMessage()
{
    char msgname[20];
    sprintf(msgname, " ceci vient de Ordi1");
    // Create message object and set source and destination field.
    Message *msg = new Message(msgname);
    return msg;
}

void Ordi1::envoiMessage(Message *msg)
{
    // Increment hop count.
    send(msg, "out");
}

class Ordi2 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi2);
void Ordi2::handleMessage(cMessage *msg)
{
        EV << "Message recu ordi2 \n";
        bubble("message accepte");  // making animation more informative...
        delete msg;
}
>>>>>>> d5904819cc100adf91884c3a8cb39cc199cb3a0b
