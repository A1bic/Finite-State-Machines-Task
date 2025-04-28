from transitions import Machine
from transitions.extensions import GraphMachine

states = ['q0', 'q1', 'q2', 'q3', 'q4']

transitions = [
    {'trigger': 'a', 'source': 'q0', 'dest': 'q1'},
    {'trigger': 'b', 'source': 'q0', 'dest': 'q0'},

    {'trigger': 'a', 'source': 'q1', 'dest': 'q1'},
    {'trigger': 'b', 'source': 'q1', 'dest': 'q2'},
    
    {'trigger': 'a', 'source': 'q2', 'dest': 'q1'},
    {'trigger': 'b', 'source': 'q2', 'dest': 'q3'},

    {'trigger': 'a', 'source': 'q3', 'dest': 'q4'},
    {'trigger': 'b', 'source': 'q3', 'dest': 'q1'},

    {'trigger': 'reset', 'source': '*', 'dest': 'q0'},

]

class DKA:
    pass

m = DKA()

machine = GraphMachine(model=m, states=states, transitions=transitions, initial='q0')

input_string = input("Введите строку для автомата: ")

if len(input_string) < 4:
    print("Строка не содержит подстроку abba")
    exit()

contains = False

for char in input_string:
    if char == 'a':
        m.a()
    elif char == 'b':
        m.b()
    else:
        m.reset()
    if m.state == 'q4':
        print("Строка содержит подстроку abba")
        contains = True
        break

if (not contains):
    print("Строка не содержит подстроку abba")

graph = m.get_graph()

graph.layout(prog="dot")
graph.draw("diagram.png")

