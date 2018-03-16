grammar Prog;

prog: decl* DefFun '\n';

decl : Type ' ' Name ';';

Type : 'int'
     | 'char';

Name : [a-zA-Z][a-zA-Z0-9]*; 

DefFun : 'void main(){}';
