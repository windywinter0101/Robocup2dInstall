// -*-c++-*-

/*!
  \file host_address.h
  \brief address class Header File.
*/

/*
 *Copyright:

 Copyright (C) Hidehisa AKIYAMA

 This code is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 *EndCopyright:
 */

/////////////////////////////////////////////////////////////////////

#ifndef RCSC_NET_HOST_ADDRESS_H
#define RCSC_NET_HOST_ADDRESS_H

#include <boost/scoped_ptr.hpp>
#include <boost/cstdint.hpp>

#include <string>

struct sockaddr_in;

namespace rcsc {

class HostAddress {
public:
    typedef boost::uint16_t PortNumber; //!< port number type
    typedef boost::uint32_t IPV4Address; //!< binary ipv4 host address type
    typedef struct sockaddr_in AddrType; //!< binary ipv4 host address type

private:

    class Impl; //!< pimpl idiom

    //! internal implementation object
    boost::scoped_ptr< Impl > M_impl;

public:

    /*!
      \brief create a null address object
     */
    HostAddress();

    /*!
      \brief create a new address object that has same address with the argument.
      \param addr copied address object.
     */
    HostAddress( const HostAddress & addr );

    /*!
      \brief create a new address object with the argument.
      \param addr raw address object
     */
    HostAddress( const AddrType & addr );

    /*!
      \brief we need the destructor definition in order to use pimpl idiom with scoped_ptr
     */
    ~HostAddress();

    /*!
      \brief copy the host address data
      \param addr other host address object.
     */
    const HostAddress & operator=( const HostAddress & addr );

    /*!
      \brief copy the host address data
      \param addr raw address object
     */
    const HostAddress & operator=( const AddrType & addr );

    /*!
      \brief the host address is set to 0.0.0.0.
     */
    void clear();

    /*!
      \brief check if the host address is 0.0.0.0
      \return checked result.
     */
    bool isNull() const;

    /*!
      \brief check if the specified address is same as this object.
      \brief checked result.
     */
    bool equals( const HostAddress & addr ) const;

    /*!
      \brief check if the specified address is same as this object.
      \brief checked result.
     */
    bool equals( const AddrType & addr ) const;

    /*!
      \brief set new address
      \param addr raw address object
     */
    void setAddress( const AddrType & addr );

    /*
      \brief get port number of this address
      \return port number
     */
    PortNumber portNumber() const;

    /*!
      \brief get IPv4 address as a number
      \return IPv4 address value (unsigned 32bit integer)
     */
    IPV4Address toIPV4Address() const;

    /*!
      \brief get the address as a string (e.g. "127.0.0.1") that is generated by inet_ntoa.
      \return host name string
     */
    std::string toHostName() const;

    /*!
      \brief get the raw address object.
      \return const reference to the raw address object.
    */
    const AddrType & toAddress() const;
};

}

#endif
