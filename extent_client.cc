// RPC stubs for clients to talk to extent_server

#include "extent_client.h"
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

extent_client::extent_client(std::string dst)
{
  sockaddr_in dstsock;
  make_sockaddr(dst.c_str(), &dstsock);
  cl = new rpcc(dstsock);
  if (cl->bind() != 0) {
    printf("extent_client: bind failed\n");
  }
}

extent_protocol::status
extent_client::create(uint32_t type, extent_protocol::extentid_t &id, chfs_command::txid_t txid)
{
  extent_protocol::status ret = extent_protocol::OK;
  // ret = es->create(type, id, txid);
  // Your lab2B part1 code goes here
  ret = cl->call(extent_protocol::create, txid, type, id);
  return ret;
}

extent_protocol::status
extent_client::get(extent_protocol::extentid_t eid, std::string &buf, chfs_command::txid_t txid)
{
  extent_protocol::status ret = extent_protocol::OK;
  // ret = es->get(eid, buf, txid);
  // Your lab2B part1 code goes here
  ret = cl->call(extent_protocol::get, txid, eid, buf);
  return ret;
}

extent_protocol::status
extent_client::getattr(extent_protocol::extentid_t eid, 
		       extent_protocol::attr &attr, chfs_command::txid_t txid)
{
  extent_protocol::status ret = extent_protocol::OK;
  // ret = es->getattr(eid, attr, txid);
  // Your lab2B part1 code goes here
  ret = cl->call(extent_protocol::getattr, txid, eid, attr);
  return ret;
}

extent_protocol::status
extent_client::put(extent_protocol::extentid_t eid, std::string buf, chfs_command::txid_t txid)
{
  extent_protocol::status ret = extent_protocol::OK;
  int r;
  // ret = es->put(eid, buf, r, txid);
  // Your lab2B part1 code goes here
  ret = cl->call(extent_protocol::put, txid, eid, buf, r);
  return ret;
}

extent_protocol::status
extent_client::remove(extent_protocol::extentid_t eid, chfs_command::txid_t txid)
{
  extent_protocol::status ret = extent_protocol::OK;
  int r;
  // ret = es->remove(eid, r, txid);
  // Your lab2B part1 code goes here
  ret = cl->call(extent_protocol::remove, txid, eid, r);
  return ret;
}

void extent_client::commit_transaction(chfs_command::txid_t txid)
{
  // es->commit_transaction(txid);
}

chfs_command::txid_t extent_client::begin_transaction()
{
  // return es->begin_transaction();
  return 0;
}


