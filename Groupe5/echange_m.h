<<<<<<< HEAD
//
// Generated file, do not edit! Created by nedtool 5.4 from echange.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __ECHANGE_M_H
#define __ECHANGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>echange.msg:15</tt> by nedtool.
 * <pre>
 * //
 * // This program is free software: you can redistribute it and/or modify
 * // it under the terms of the GNU Lesser General Public License as published by
 * // the Free Software Foundation, either version 3 of the License, or
 * // (at your option) any later version.
 * // 
 * // This program is distributed in the hope that it will be useful,
 * // but WITHOUT ANY WARRANTY; without even the implied warranty of
 * // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * // GNU Lesser General Public License for more details.
 * // 
 * // You should have received a copy of the GNU Lesser General Public License
 * // along with this program.  If not, see http://www.gnu.org/licenses/.
 * //
 * message Echange
 * {
 *     string texto;
 * }
 * </pre>
 */
class Echange : public ::omnetpp::cMessage
{
  protected:
    ::omnetpp::opp_string texto;

  private:
    void copy(const Echange& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Echange&);

  public:
    Echange(const char *name=nullptr, short kind=0);
    Echange(const Echange& other);
    virtual ~Echange();
    Echange& operator=(const Echange& other);
    virtual Echange *dup() const override {return new Echange(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getTexto() const;
    virtual void setTexto(const char * texto);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Echange& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Echange& obj) {obj.parsimUnpack(b);}


#endif // ifndef __ECHANGE_M_H

=======
//
// Generated file, do not edit! Created by nedtool 5.4 from echange.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __ECHANGE_M_H
#define __ECHANGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>echange.msg:15</tt> by nedtool.
 * <pre>
 * //
 * // This program is free software: you can redistribute it and/or modify
 * // it under the terms of the GNU Lesser General Public License as published by
 * // the Free Software Foundation, either version 3 of the License, or
 * // (at your option) any later version.
 * // 
 * // This program is distributed in the hope that it will be useful,
 * // but WITHOUT ANY WARRANTY; without even the implied warranty of
 * // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * // GNU Lesser General Public License for more details.
 * // 
 * // You should have received a copy of the GNU Lesser General Public License
 * // along with this program.  If not, see http://www.gnu.org/licenses/.
 * //
 * message Echange
 * {
 *     string texto;
 * }
 * </pre>
 */
class Echange : public ::omnetpp::cMessage
{
  protected:
    ::omnetpp::opp_string texto;

  private:
    void copy(const Echange& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Echange&);

  public:
    Echange(const char *name=nullptr, short kind=0);
    Echange(const Echange& other);
    virtual ~Echange();
    Echange& operator=(const Echange& other);
    virtual Echange *dup() const override {return new Echange(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual const char * getTexto() const;
    virtual void setTexto(const char * texto);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Echange& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Echange& obj) {obj.parsimUnpack(b);}


#endif // ifndef __ECHANGE_M_H

>>>>>>> d5904819cc100adf91884c3a8cb39cc199cb3a0b
