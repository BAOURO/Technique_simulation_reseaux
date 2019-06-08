/*
 * Groupe3.cc
 *
 *  Created on: 2 juin 2019
 *      Author: harrys
 */
#include <stdio.h>
#include <omnetpp.h>
#include <string.h>


using namespace omnetpp;
#include <Message_m.h>

/**
 *
 *  Ordinateur 1
 */

class Sender: public cSimpleModule {
public:
    Sender();
    virtual ~Sender();
private:
    Message *msg;
protected:
    virtual Message *generateMessage();
    virtual void forwardMessage(Message *msg);
    virtual void initialize() override;
    virtual void finish() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Sender);

simtime_t timerInterval;
cMessage *emptyMessage;

Sender::Sender(){
    emptyMessage=nullptr;
}

void Sender::initialize()
{
    timerInterval = 5.0;
    emptyMessage=new cMessage("Timeout");
    this->msg = generateMessage();
    EV << "Envoi du premier message:\n";
    forwardMessage(this->msg);
    scheduleAt(simTime()+timerInterval, emptyMessage);
}

void Sender::handleMessage(cMessage *msg)
{
    if (msg==emptyMessage)
    {
        EV << "Delai depasse; Renvoi du message...\n";
        //Message *newMsg = generateMessage();
        //send(newMsg, "out");
        forwardMessage(this->msg);
        //cancelEvent(emptyMessage);
        scheduleAt(simTime()+timerInterval, emptyMessage);
    } else {
        EV << "Message: " << msg->getName() << "\n";
        delete msg;
        cancelEvent(emptyMessage);
        delete this->msg;

        this->msg = generateMessage();
        forwardMessage(this->msg);
        scheduleAt(simTime()+timerInterval, emptyMessage);
    }
    //scheduleAt(simTime()+timerInterval, emptyMessage);
}

Message *Sender::generateMessage()
{
    char mess[60]="Ceci vient de ";
    Message *msg = new Message(strcat(mess, getName()));
    msg->setSender(getName());
    return msg;
}

void Sender::forwardMessage(Message *msg)
{
    send((Message *)msg->dup(), "out");
}

void Sender::finish(){
    cancelAndDelete(msg);
}

Sender::~Sender()
{
    cancelAndDelete(emptyMessage);
    delete msg;
}

/**
 *
 *  Ordinateur 2
 */

class Receiver : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Receiver);

void Receiver::handleMessage(cMessage *msg)
{
    if (uniform(0, 1) < 0.5) {
        EV << "Message perdu: " << msg->getName() << "\n";
        bubble("Perdu!");
        delete msg;
    }
    else {
        EV << msg << ": Message recu .\n";
        delete msg;
        send(new cMessage("OK"), "out");
    }
}


