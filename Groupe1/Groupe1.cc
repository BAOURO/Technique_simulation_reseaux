#include <stdio.h>
#include <string.h>
#include <omnetpp.h>
#include <Message_m.h>
#include <iostream>
#include <fstream>

using namespace omnetpp;
using namespace std;

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

// initialisation du le constructeur

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

    // Génère et envoi le premier message.
    EV << "Sending initial message\n";
    Message *msg = new Message();
    send(msg, "out");
    scheduleAt(simTime()+timeout, timeoutEvent);
}


// Définit le comportement des ordinateurs à la reception d'un message
void Ordi1::handleMessage(cMessage *msg)
{
    ofstream fichier("message.csv", ios::out | ios::app);

    if (msg == timeoutEvent) {
        // If we receive the timeout event, that means the packet hasn't
        // arrived in time and we have to re-send it.
        EV << "Sending message\n";
        Message *newMsg = new Message();

        send(newMsg, "out");
        scheduleAt(simTime()+timeout, timeoutEvent);

        // On écrit un message dans le fichier excel
        if(fichier){
                fichier << "Ceci est un message qui vient d'ordinateur 1 " <<endl;

            }
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
        bubble("Received");  // Affiche une bulle d'information
        delete msg;
    }
    else {
        delete msg;
    }
}
