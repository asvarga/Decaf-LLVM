

## This program will automatically write some of the tedious AST/visitor code
## Some edits will need to be made, like differentiating repeated declarations


data = [
    ("Super", ["Type"]),
    ("MethodBody", [["Formal"], ["Statement"]]),
    # ("Class", [["Class"]]),
    ("FieldDecl", [["Field"]]),
    ("Field", ["Initializer"]),
    ("Method", ["Type", "MethodBody"]),
    ("Constructor", ["Type", "MethodBody"]),
    ("Formal", ["Type"]),
    ("DeclStatement", [["Local"]]),
    ("Local", ["Expression"]),
    ("IfStatement", ["Expression", "Statement", "Statement"]),
    ("ExpressionStatement", ["Expression"]),
    ("WhileStatement", ["Expression", "Statement"]),
    ("ReturnStatement", ["Expression"]),
    ("ContinueStatement", []),
    ("BreakStatement", []),
    ("BlockStatement", ["Block"]),
    ("Block", [["Statement"]]),
    ("SuperStatement", ["Call"]),
    ("Call", ["Name", ["Expression"]]),
    ("OpExpression", ["Expression", "Expression"]),
    ("NewArray", ["Type", ["Expression"]]),
    ("ArrayRef", ["Expression", "Expression"]),

    ("Type", []),
    ("Expression", []),
    ("Initializer", []),
    ("Statement", []),
    ("Name", [])
]

def forwDecl(d):
    return f"class {d[0]}A;"

def header(d):
    def member(a):
        if isinstance(a, list): 
            a = a[0]
            return f"ListA *{a.lower()}List;"
        return f"{a}A *{a.lower()};"
    members = "\n    ".join(map(member, d[1]))

    def carg(a):
        if isinstance(a, list): 
            a = a[0]
            return f"ListA *{a[0].lower()}s"
        return f"{a}A *{a[0].lower()}"
    cargs = ", ".join(map(carg, d[1]))

    def init(a):
        if isinstance(a, list): 
            a = a[0]
            return f"{a.lower()}List({a[0].lower()}s)"
        return f"{a.lower()}({a[0].lower()})"
    inits = ": "+", ".join(map(init, d[1])) if d[1] else ""

    def getter(a):
        if isinstance(a, list): 
            a = a[0]
            return f"ListA *get{a}List() {{ return {a.lower()}List; }};"
        return f"{a}A *get{a}() {{ return {a.lower()}; }};"
    getters = "\n    ".join(map(getter, d[1]))

    return f"""class {d[0]}A : public AST {{
    {members} 
public: 
    {d[0]}A({cargs}){inits} {{}};
    {getters}
    virtual void accept(Visitor& v);
}};"""


def visitah(d): return f"virtual void visit({d[0]}A* a) = 0;"
def visith(d): return f"virtual void visit({d[0]}A* a);"


def accept(d):
    def child(a):
        if isinstance(a, list): 
            a = a[0]
            # return f"for (AST *a : this->{a.lower()}List) {{ a->accept(v); }}"
            return f"this->{a.lower()}List->accept(v);"
        return f"this->{a.lower()}->accept(v);"
    children = "\n    ".join(map(child, d[1]))

    return f"""void {d[0]}A::accept(Visitor& v) {{ 
    v.visit(this);
    {children}
}}"""


def printer(d):
    return f"""void PrinterV::visit({d[0]}A* a) {{ 
    cout << "Visiting {d[0]}A\\n"; 
}}"""

def counter(d):
    return f"void CounterV::visit({d[0]}A* a) {{ cout << this->c++ << \"\\n\"; }}"



# data = data[:2]
# data = data2
print("\n\n")
for d in data: print(forwDecl(d))
print("\n\n")
for d in data: print(header(d))
print("\n\n")
for d in data: print(visitah(d))
print("\n\n")
for d in data: print(visith(d))
print("\n\n")
for d in data: print(accept(d))
print("\n\n")
for d in data: print(printer(d))
print("\n\n")
for d in data: print(counter(d))
