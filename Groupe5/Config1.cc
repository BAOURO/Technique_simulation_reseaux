/*
 * Config1.cc
 *
 *  Created on: Jun 15, 2019
 *      Author: Death-$hot
 */

#include<stdio.h>
#include<string.h>
#include<omnetpp.h>

using namespace omnetpp;
#include <echange_m.h>

class Ordi_1: public cSimpleModule {
public:
    Ordi_1();
    virtual ~Ordi_1();
private:
    simtime_t timeout;
    Echange *timeoutEvent;
    Echange msg ;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;


};

Define_Module(Ordi_1);

Ordi_1::Ordi_1(){
    timeoutEvent=nullptr;
}

Ordi_1::~Ordi_1() {
      cancelAndDelete(timeoutEvent);
}
void Ordi_1::initialize(){
    timeout = 5;
timeoutEvent = new Echange("Ce message provient de Ordi_1.  ");

// On genere et on envoie le premier message.
EV << "Initialisation du message\n";
 Echange *msg = new Echange ("Message de ordinateur 1 ");
send(msg, "out");
scheduleAt(simTime()+timeout, timeoutEvent);
}

void Ordi_1::handleMessage(cMessage *msg)
{
    if (msg == timeoutEvent) {
        // si on recoit le timeout Event cela signifie que le message n'est pas arrivé à temps
        // donc on doit le renvoyer.
        EV << "Ceci vient de ordi1 \n";
        Echange *msg = new Echange("Ceci vient de ordi1. ");
        send(msg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
}



class Ordi_2 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi_2);

void Ordi_2::handleMessage(cMessage *msg)
{
    if (uniform(0, 1) < 0.5) {
        EV << "\"message\" perdu " << msg << endl;
        bubble("message perdu");
        delete msg;
    }
    else {
        EV << msg << " recu, renvoie ack .\n";
        delete msg;
    }
}
