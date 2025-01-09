#pragma once

extern "C" {
#include <yyjson.h>
}

#include <memory>
#include <string>

namespace EasyYYJSON
{
    // Forward declaration of 
    class Value;
    class Array;
    class Object;
    class Document;
    class ConstValue;
    class ConstArray;
    class ConstObject;
    class ConstDocument;

    enum StringifyFlag
    {
        NoFlag              = 0x0000,
        PrettyIndent        = 0x0001,
        WideIndent          = 0x0002,
        ASCIIOnly           = 0x0010,
        AllowInvalidUnicode = 0x0020,
        NewLineEnding       = 0x0100
    }

    // Mutable json Document
    class Document
    {
        public:
            explicit Document();
            explicit Document(const std::string &json);

            bool parse(const std::string &json);

            /*
            * Faster parsing, json is not useable after calling this function
            */
            bool parseInSitu(std::string &json);

            Value getRoot();
            bool setRoot(Value &value);

            std::string stringify(StringifyFlag flags = StringifyFlag::NoFlag);
            friend std::ostream &operator << (std::ostream &os, const Document &doc)
            {
                os << doc.stringify(StringifyFlag::PrettyIndent | StringifyFlag::NewLineEnding);
                return os;
            }
        protected:
        private:
            std::shared_ptr<yyjson_mut_doc> _doc;
            friend class Value;
    };

    // Mutable json Value
    class Value
    {
        public:
            explicit Value();
        protected:
        private:
            std::shared_ptr<yyjson_mut_doc> _doc;
    };    
    
    // Mutable json Array
    class Array
    {
        public:
            explicit Array();
        protected:
        private:
            explicit Array(std::shared_ptr<yyjson_mut_doc> doc, yyjson_mut_val *arr);
            std::shared_ptr<yyjson_mut_doc> _doc;
            yyjson_mut_val *_arr;
    };

    // Mutable json Object
    class Object
    {
        public:
            explicit Object();
        protected:
        private:
            explicit Object(std::shared_ptr<yyjson_mut_doc> doc, yyjson_mut_val *obj);
            std::shared_ptr<yyjson_mut_doc> _doc;
            yyjson_mut_val *_obj;
    };
    
    // Immutable json document
    class ConstDocument
    {
        public:
            explicit ConstDocument();
        protected:
        private:
            std::shared_ptr<yyjson_doc> _doc;
    };

    // Immutable json value
    class ConstValue
    {
        public:
            explicit ConstValue();
        protected:
        private:
            std::shared_ptr<yyjson_doc> _doc;
    };    
    
    // Immutable json array
    class ConstArray
    {
        public:
            explicit ConstArray();
        protected:
        private:
            std::shared_ptr<yyjson_doc> _doc;
    };

    // Immutable json object
    class ConstObject
    {
        public:
            explicit ConstObject();
        protected:
        private:
            std::shared_ptr<yyjson_doc> _doc;
    };
}