// -*- mode: cpp; mode: fold -*-
// Description								/*{{{*/
/* ######################################################################

   CacheDB
   
   Simple uniform interface to a cache database.
   
   ##################################################################### */
									/*}}}*/
#ifndef CACHEDB_H
#define CACHEDB_H

#include <apt-pkg/debfile.h>
#include <apt-pkg/hashes.h>

#include <string>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "contents.h"
#include "sources.h"

class FileFd;


class CacheDB
{
   public:

   // Data collection helpers
   debDebFile::MemControlExtract Control;
   ContentsExtract Contents;
   DscExtract Dsc;
   HashStringList HashesList;

   // Runtime statistics
   struct Stats
   {
      double Bytes;
      double MD5Bytes;
      double SHA1Bytes;
      double SHA256Bytes;
      double SHA512Bytes;
      unsigned long Packages;
      unsigned long Misses;  
      unsigned long long DeLinkBytes;
      
      inline void Add(const Stats &S) {};
      Stats() : Bytes(0), MD5Bytes(0), SHA1Bytes(0), SHA256Bytes(0),
		SHA512Bytes(0),Packages(0), Misses(0), DeLinkBytes(0) {};
   } Stats;
   
   bool ReadyDB(std::string const &DB = "") { return true; }
   inline bool DBFailed() { return true;};
   inline bool Loaded() {return true;};
   
   inline unsigned long long GetFileSize(void) {return 0;}
   
   bool SetFile(std::string const &FileName,struct stat St,FileFd *Fd) { return true; };

   // terrible old overloaded interface
   bool GetFileInfo(std::string const &FileName,
	 bool const &DoControl,
	 bool const &DoContents,
	 bool const &GenContentsOnly,
	 bool const DoSource,
	 unsigned int const DoHashes,
	 bool const &checkMtime = false) { return false; }

   bool Finish() { return true; };
   
   bool Clean() { return true; };
   
   explicit CacheDB(std::string const &DB) {};
   ~CacheDB() {};
};
    
#endif
