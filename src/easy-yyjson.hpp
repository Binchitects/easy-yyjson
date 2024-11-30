#pragma once

#include <memory>
#include <string>
#include <yyjson.h>

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

    // Mutable json Document
    class Document
    {
        public:
            explicit Document();
        protected:
        private:
            std::shared_ptr<yyjson_mut_doc> _doc;
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
            std::shared_ptr<yyjson_mut_doc> _doc;
    };

    // Mutable json Object
    class Object
    {
        public:
            explicit Object();
        protected:
        private:
            std::shared_ptr<yyjson_mut_doc> _doc;
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