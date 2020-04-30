// Win32System.h
// Context Free
// ---------------------
// Copyright (C) 2005-2007 Mark Lentczner - markl@glyphic.com
// Copyright (C) 2007-2013 John Horigan - john@glyphic.com
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
// 
// Mark Lentczner can be contacted at markl@glyphic.com or at
// Mark Lentczner, 1209 Villa St., Mountain View, CA 94041-1123, USA
//
// John Horigan can be contacted at john@glyphic.com or at
// John Horigan, 1209 Villa St., Mountain View, CA 94041-1123, USA
//
//

#ifndef INCLUDE_WIN32_SYSTEM
#define INCLUDE_WIN32_SYSTEM

#include "cfdg.h"

class Win32System : public AbstractSystem
{
protected:
    void clearAndCR() override;
public:
    Win32System() = default;
    ~Win32System() = default;

    void catastrophicError(const char* what) override;

    istr_ptr tempFileForRead(const FileString& path) override;
    ostr_ptr tempFileForWrite(TempType tt, FileString& nameOut) override;
    const FileChar* tempFileDirectory() override;
    std::vector<FileString> findTempFiles() override;
    int deleteTempFile(const FileString& name) override;
    size_t getPhysicalMemory() override;

    std::string relativeFilePath(
        const std::string& base, const std::string& rel) override;

    std::wstring normalize(const std::string&) override;
};

#endif // INCLUDE_WIN32_SYSTEM
