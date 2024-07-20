/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** DLLoader
*/

#pragma once

template <typename T>
class DLLoader {
    public:
        DLLoader()
        {
        };
        DLLoader(std::string path)
        {
            _handle = dlopen(path.c_str(), RTLD_NOW);
            if (!_handle)
                throw std::runtime_error(dlerror());
        };
        void setHandle(std::string path)
        {
            if (_handle)
                dlclose(_handle);
            _handle = dlopen(path.c_str(), RTLD_NOW);
            if (!_handle)
                throw std::runtime_error(dlerror());
        };
        T *getInstance(const std::string &name)
        {
            T *(*create)() = (T *(*)())dlsym(_handle, name.c_str());
            if (!create)
                throw std::runtime_error(dlerror());
            return create();
        };
        ~DLLoader(){
            dlclose(_handle);
        };

    protected:
    private:
        void *_handle;
};
