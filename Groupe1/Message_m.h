//
// Generated file, do not edit! Created by nedtool 5.1 from Message.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __MESSAGE_M_H
#define __MESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0501
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>Message.msg:1</tt> by nedtool.
 * <pre>
 * message Message
 * {
 *     int source;
 *     int hopCount;
 * }
 * </pre>
 */
class Message : public ::omnetpp::cMessage
{
  protected:
    int source;
    int hopCount;

  private:
    void copy(const Message& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Message&);

  public:
    Message(const char *name=nullptr, short kind=0);
    Message(const Message& other);
    virtual ~Message();
    Message& operator=(const Message& other);
    virtual Message *dup() const override {return new Message(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getSource() const;
    virtual void setSource(int source);
    virtual int getHopCount() const;
    virtual void setHopCount(int hopCount);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Message& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Message& obj) {obj.parsimUnpack(b);}


#endif // ifndef __MESSAGE_M_H

