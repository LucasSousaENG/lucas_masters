#ifndef WPG__VISIBILITY_CONTROL_H_
#define WPG__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define WPG_EXPORT __attribute__ ((dllexport))
    #define WPG_IMPORT __attribute__ ((dllimport))
  #else
    #define WPG_EXPORT __declspec(dllexport)
    #define WPG_IMPORT __declspec(dllimport)
  #endif
  #ifdef WPG_BUILDING_LIBRARY
    #define WPG_PUBLIC WPG_EXPORT
  #else
    #define WPG_PUBLIC WPG_IMPORT
  #endif
  #define WPG_PUBLIC_TYPE WPG_PUBLIC
  #define WPG_LOCAL
#else
  #define WPG_EXPORT __attribute__ ((visibility("default")))
  #define WPG_IMPORT
  #if __GNUC__ >= 4
    #define WPG_PUBLIC __attribute__ ((visibility("default")))
    #define WPG_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define WPG_PUBLIC
    #define WPG_LOCAL
  #endif
  #define WPG_PUBLIC_TYPE
#endif
#endif  // WPG__VISIBILITY_CONTROL_H_
// Generated 23-Aug-2023 19:28:55
// Copyright 2019-2020 The MathWorks, Inc.
