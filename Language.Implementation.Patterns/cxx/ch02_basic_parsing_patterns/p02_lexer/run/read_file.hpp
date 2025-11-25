#pragma once

#include <fstream>
#include <string>
#include <cassert>

static
std::string read_file(const char* file_path) {
    std::string input;
    std::ifstream ifile(file_path, std::ios::binary);
    if (ifile.is_open())
    {
        ifile.seekg(0, std::ios_base::end);
        auto length = ifile.tellg();
        ifile.seekg(0, std::ios_base::beg);

        input.resize(static_cast<size_t>(length));
        ifile.read(reinterpret_cast<char*>(input.data()), length);

        assert(!ifile.fail() && length == ifile.gcount());

        ifile.close();
    }

    return input;
}
