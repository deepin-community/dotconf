/* ====================================================================
 * The Apache Software License, Version 1.1
 *
 * Copyright (c) 2000 The Apache Software Foundation.  All rights
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. The end-user documentation included with the redistribution,
 *    if any, must include the following acknowledgment:
 *       "This product includes software developed by the
 *        Apache Software Foundation (http://www.apache.org/)."
 *    Alternately, this acknowledgment may appear in the software itself,
 *    if and wherever such third-party acknowledgments normally appear.
 *
 * 4. The names "Apache" and "Apache Software Foundation" must
 *    not be used to endorse or promote products derived from this
 *    software without prior written permission. For written
 *    permission, please contact apache@apache.org.
 *
 * 5. Products derived from this software may not be called "Apache",
 *    nor may "Apache" appear in their name, without prior written
 *    permission of the Apache Software Foundation.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE APACHE SOFTWARE FOUNDATION OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 *
 * This software consists of voluntary contributions made by many
 * individuals on behalf of the Apache Software Foundation.  For more
 * information on the Apache Software Foundation, please see
 * <http://www.apache.org/>.
 *
 * Portions of this software are based upon public domain software
 * originally written at the National Center for Supercomputing Applications,
 * University of Illinois, Urbana-Champaign.
 */  
    
/*
 * Structures and types used to implement opendir/readdir/closedir
 * on Windows 95/NT.
 */ 
    
#ifndef APACHE_READDIR_H
#define APACHE_READDIR_H
    
#ifdef WIN32
    
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
    
/* struct dirent - same as Unix */ 
    struct dirent {
	long d_ino;		/* inode (always 1 in WIN32) */
	 off_t d_off;		/* offset to this dirent */
	 unsigned short d_reclen;	/* length of d_name */
	 char d_name[_MAX_FNAME + 1];	/* filename (null terminated) */
};

/* typedef DIR - not the same as Unix */ 
    typedef struct {
	long handle;		/* _findfirst/_findnext handle */
	 short offset;		/* offset into directory */
	 short finished;	/* 1 if there are not more files */
	 struct _finddata_t fileinfo;	/* from _findfirst/_findnext */
	char *dir;		/* the dir we are reading */
	 struct dirent dent;	/* the dirent to return */
} DIR;

/* Function prototypes */ 
    DIR * opendir(const char *);
struct dirent *readdir(DIR *);
int closedir(DIR *);

#endif	/* WIN32 */
    
#endif	/* ndef APACHE_READDIR_H */
