#pragma once

class Variable
{

public:

    Variable & operator = ( const Variable & unVariable );

    Variable ( const Variable & unVariable );

    Variable ( );

    virtual ~Variable ( );

};
