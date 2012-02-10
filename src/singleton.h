/****************************************************************************
**
**    This file is part of Lorris.
**    Copyright (C) 2012 Vojtěch Boček
**
**    Contact: <vbocek@gmail.com>
**             https://github.com/Tasssadar
**
**    Lorris is free software: you can redistribute it and/or modify
**    it under the terms of the GNU General Public License as published by
**    the Free Software Foundation, either version 3 of the License, or
**    (at your option) any later version.
**
**    Lorris is distributed in the hope that it will be useful,
**    but WITHOUT ANY WARRANTY; without even the implied warranty of
**    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**    GNU General Public License for more details.
**
**    You should have received a copy of the GNU General Public License
**    along with Lorris.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

// (c) AbyssX Group
#ifndef SINGLETON_H
#define SINGLETON_H

//! Scott Bilas' Singleton implementation, with proper casting mod.
template <class T> class Singleton
{
    public:
        //! Constructor: Sets the static pointer.
      /*  Singleton()
        {
     //       msSingleton = static_cast<T *>(this);
        }
        //! Destructor: Sets the static pointer to NULL, just in case.
        ~Singleton()
        {
       //     msSingleton = 0x00;
        } */
        //! GetSingleton(): Returns a reference of the class.
        static T &GetSingleton(void)
        {
            if(!msSingleton)
                msSingleton = new T;
            return *msSingleton;
        }
        //! GetSingletonPtr(): Returns a pointer to the class.
        static T *GetSingletonPtr(void)
        {
            return msSingleton;
        }

        static void Destroy(void)
        {
            delete msSingleton;
            msSingleton = NULL;
        }

    private:
        //! msSingleton: The static variable which holds the pointer to the singleton.
        static T *msSingleton;
};

//! Define the following for any class that inherits from Singleton.
template <class T> T *Singleton<T>::msSingleton = 0;

#endif