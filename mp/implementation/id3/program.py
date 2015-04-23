import Node

data = [[]]
f = open('Switch.csv')
for line in f:
	line = line.strip("\r\n")
	data.append(line.split(','))
data.remove([])
tree = {'day': {'Monday': {'time': {'Morning': {'temp': {'hot': {'light': {'dark': 'YES', 'dim': 'YES', 'bright': 'NO', 'moderate': 'NO'}}}}, 'Afternoon': {'temp': {'hot': 'YES', 'cool': 'NO'}}, 'Night': {'temp': {'cold': 'YES', 'hot': 'NO', 'cool': {'light': {'dark': 'YES', 'moderate': 'NO'}}}}}}, 'Tuesday': {'time': {'Night': 'YES', 'Afternoon': {'temp': {'hot': {'light': {'dim': 'NO', 'moderate': 'YES'}}, 'cold': {'light': {'dim': 'YES'}}}}, 'Morning': {'temp': {'hot': {'light': {'dim': 'YES', 'bright': 'YES'}}, 'cold': {'light': {'dark': 'YES', 'dim': 'NO', 'bright': 'YES'}}, 'cool': {'light': {'dim': 'YES', 'moderate': 'NO'}}}}}}, 'Friday': {'time': {'Morning': 'NO', 'Afternoon': {'temp': {'cold': {'light': {'dark': 'YES', 'bright': 'YES'}}, 'hot': {'light': {'dim': 'NO', 'moderate': 'YES'}}, 'cool': {'light': {'dark': 'YES', 'dim': 'YES', 'bright': 'YES'}}}}, 'Night': {'temp': {'cold': {'light': {'dark': 'YES', 'bright': 'YES'}}, 'hot': 'YES'}}}}, 'Wednesday': {'time': {'Morning': {'temp': {'hot': {'light': {'dark': 'YES', 'dim': 'NO', 'moderate': 'NO'}}}}, 'Afternoon': {'temp': {'cold': 'YES', 'hot': 'YES', 'cool': {'light': {'dark': 'YES', 'dim': 'NO'}}}}, 'Night': {'temp': {'hot': 'YES', 'cool': 'NO'}}}}, 'Thursday': {'time': {'Night': {'temp': {'cold': {'light': {'dark': 'YES'}}, 'hot': {'light': {'dark': 'NO', 'bright': 'YES'}}}}, 'Afternoon': {'temp': {'cold': 'NO', 'hot': 'NO', 'cool': 'YES'}}, 'Morning': {'temp': {'cold': {'light': {'dark': 'NO', 'bright': 'YES'}}, 'cool': 'NO'}}}}, 'Sunday': {'time': {'Night': {'temp': {'hot': {'light': {'bright': 'YES'}}}}, 'Afternoon': {'temp': {'hot': 'NO', 'cold': {'light': {'dim': 'YES'}}, 'cool': 'NO'}}, 'Morning': {'temp': {'hot': 'NO', 'cold': 'NO', 'cool': 'YES'}}}}, 'Saturday': {'time': {'Morning': {'temp': {'hot': {'light': {'dim': 'YES'}}, 'cold': {'light': {'bright': 'YES'}}, 'cool': {'light': {'dim': 'YES', 'moderate': 'NO'}}}}, 'Afternoon': {'temp': {'hot': 'YES', 'cold': 'NO', 'cool': 'YES'}}, 'Night': {'temp': {'hot': {'light': {'dark': 'YES', 'bright': 'YES', 'moderate': 'NO'}}, 'cool': {'light': {'dark': 'YES', 'dim': 'YES', 'moderate': 'NO'}}}}}}}}
attributes = ['day', 'time', 'temp', 'light', 'switch']
count = 0
for entry in data:
	count += 1
	tempDict = tree.copy()
	result = ""
	while(isinstance(tempDict, dict)):
		root = Node.Node(tempDict.keys()[0], tempDict[tempDict.keys()[0]])
		tempDict = tempDict[tempDict.keys()[0]]
		index = attributes.index(root.value)
		value = entry[index]
		if(value in tempDict.keys()):
			child = Node.Node(value, tempDict[value])
			result = tempDict[value]
			tempDict = tempDict[value]
		else:
			print "can't process input %s" % count
			result = "?"
			break
	print ("entry%s = %s" % (count, result))
