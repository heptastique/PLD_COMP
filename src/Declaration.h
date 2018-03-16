#pragma once

class Declaration {

public:

    Declaration &operator=(const Declaration &unDeclaration);

    Declaration(const Declaration &unDeclaration);

    Declaration();

    virtual ~Declaration();

};
