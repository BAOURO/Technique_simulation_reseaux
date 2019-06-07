#include <stdio.h>
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class Ordi_1 : public cSimpleModule
{
  private:
    simtime_t timeout;
    cMessage *timeoutEvent;
    int seq;  // numero de la sequence de message
    cMessage *message;  // message renvoyer au timeout

  public:
    Ordi_1();
    virtual ~Ordi_1();

  protected:
    virtual cMessage *generateNewMessage();
    virtual void sendCopyOf(cMessage *msg);
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi_1);

Ordi_1::Ordi_1()
{
    timeoutEvent = message = nullptr;
}

Ordi_1::~Ordi_1()
{
    cancelAndDelete(timeoutEvent);
    delete message;
}

void Ordi_1::initialize()
{
    // Initialisation des variables .
    seq = 0;
    timeout = 1.0;
    timeoutEvent = new cMessage("timeoutEvent");

    // ON genere et on envoi le premier msg.
    EV << "Sending initial message\n";
    message = generateNewMessage();
    sendCopyOf(message);
    scheduleAt(simTime()+timeout, timeoutEvent);
}

void Ordi_1::handleMessage(cMessage *msg)
{
    if (msg == timeoutEvent) {
        // si on reçoit le timeout event, cela signifie que le paquet
        // n'est pas arrivé a temps et on doit le renvoyer.
        EV << "Timeout expired, resending message and restarting timer\n";
        sendCopyOf(message);
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
    else {  // si le msg arrive
            // Ack est recu!
        EV << "Received: " << msg->getName() << "\n";
        delete msg;

        // on supprime egalement le msg stocker et on annule le timeout event.
        EV << "Timer cancelled.\n";
        cancelEvent(timeoutEvent);
        delete message;

        // pret a envoyer un nouveau msg.
        message = generateNewMessage();
        sendCopyOf(message);
        scheduleAt(simTime()+timeout, timeoutEvent);
    }
}

cMessage *Ordi_1::generateNewMessage()
{
    // on genere les msg avec differents nom.
    char msgname[20];
    sprintf(msgname, "-%d message provenant de Ordi1 recu ", ++seq);
    cMessage *msg = new cMessage(msgname);
    return msg;
}

void Ordi_1::sendCopyOf(cMessage *msg)
{
    // Duplique le msg et envoi un copie.
    cMessage *copy = (cMessage *)msg->dup();
    send(copy, "out");
}


class Ordi_2 : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Ordi_2);

void Ordi_2::handleMessage(cMessage *msg)
{
    if (uniform(0, 1) < 0.1) {
        EV << "\"message\" perdu " << msg << endl;
        bubble("message perdu");
        delete msg;
    }
    else {
        EV << msg << " recu, renvoie ack .\n";
        delete msg;
        send(new cMessage("ack"), "out");
    }
}





