#pragma once

class Function {


public:

    Function &operator=(const Function &unFunction);

    Function(const Function &unFunction);

    Function();


    virtual ~Function();
};