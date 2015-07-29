// Copyright (c) 2013, Fabrice Robinet
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef __GLTF_PROFILE__
#define __GLTF_PROFILE__

typedef std::unordered_map<std::string ,unsigned int> GLEnumForString;

namespace GLTF
{
    class GLTFProfile
    {
    public:
        virtual ~GLTFProfile();
        virtual unsigned int getGLTypeForComponentTypeAndType(const std::string& componentType, const std::string& type) = 0;
        virtual std::string getGLSLTypeForGLType(unsigned int glType) = 0;
        virtual size_t getComponentsCountForGLType(unsigned int glType) = 0;
        virtual std::string id() = 0;
        virtual size_t sizeOfGLType(unsigned int glType) = 0;
        virtual unsigned int getGLComponentTypeForGLType(unsigned int glType) = 0;
        virtual std::string getTypeForGLType(unsigned int glType) = 0;
        static size_t getComponentsCountForType(const std::string& type);
        unsigned int getGLenumForString(const std::string&);
        virtual std::shared_ptr<JSONValue> defaultValueForState(const std::string& state) = 0;
        virtual bool isDefaultValueForState(const std::string& state, std::shared_ptr<JSONValue> value) = 0;
    protected:
        void setGLenumForString(const std::string& , unsigned int);
    private:
        GLEnumForString _glEnumForString;
    };
}

#endif