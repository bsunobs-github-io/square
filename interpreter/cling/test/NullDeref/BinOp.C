//------------------------------------------------------------------------------
// CLING - the C++ LLVM-based InterpreterG :)
//
// This file is dual-licensed: you can choose to license it under the University
// of Illinois Open Source License or the GNU Lesser General Public License. See
// LICENSE.TXT for details.
//------------------------------------------------------------------------------

// RUN: cat %s | %cling --ptrcheck -Xclang -verify
// XFAIL: powerpc64
//This file checks a pointer load operation for null prt dereference.
int *p = 0;
int x;
x = *p + 2; // expected-warning {{null passed to a callee that requires a non-null argument}}
x = 2 + *p; // expected-warning {{null passed to a callee that requires a non-null argument}}

x = *p > 2; // expected-warning {{null passed to a callee that requires a non-null argument}}
x = 2 > *p; // expected-warning {{null passed to a callee that requires a non-null argument}}
