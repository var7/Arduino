import DecisionTree

def main():
    #Insert input file
    """
    IMPORTANT: Change this file path to change training data 
    """
    file = open('SwitchTraining.csv')
    """
    IMPORTANT: Change this variable to change target attribute 
    """
    target = "switch"
    data = [[]]
    for line in file:
        line = line.strip("\r\n")
        #print line
        data.append(line.split(','))
        #print "for", data
    #print "1, ", data
    data.remove([])
    attributes = data[0]
    #print attributes
    data.remove(attributes)
    #print "2", data
    #Run ID3
    tree = DecisionTree.makeTree(data, attributes, target, 0)
    print "generated decision tree"
    #Generate program
    file = open('program.py', 'w')
    file.write("import Node\nimport serial\nimport time\n\n")
    #open input file
    file.write("ser = serial.Serial('/dev/cu.usbmodem14111', 9600)\n")
    file.write("time.sleep(2)\n")
    file.write("connnected = False\n\n")
    file.write("while not connnected:\n")
    file.write("\tserin = ser.read()\n")
    file.write("\tconnnected = True\n\n")
    #connect arduino
    file.write("data = [[]]\n")
    """
    IMPORTANT: Change this file path to change testing data 
    """
    file.write("f = open('Switch.csv')\n")
    #gather data
    file.write("for line in f:\n\tline = line.strip(\"\\r\\n\")\n\tdata.append(line.split(','))\n")
    file.write("data.remove([])\n")
    #input dictionary tree
    file.write("tree = %s\n" % str(tree))
    file.write("attributes = %s\n" % str(attributes))
    file.write("count = 0\n")
    file.write("for entry in data:\n")
    file.write("\tcount += 1\n")
    #copy dictionary
    file.write("\ttempDict = tree.copy()\n")
    file.write("\tresult = \"\"\n")
    file.write("\tser.flush()\n")
    #generate actual tree
    file.write("\twhile(isinstance(tempDict, dict)):\n")
    file.write("\t\troot = Node.Node(tempDict.keys()[0], tempDict[tempDict.keys()[0]])\n")
    file.write("\t\ttempDict = tempDict[tempDict.keys()[0]]\n")
    #this must be attribute
    file.write("\t\tindex = attributes.index(root.value)\n")
    file.write("\t\tvalue = entry[index]\n")
    #ensure that key exists
    file.write("\t\tif(value in tempDict.keys()):\n")
    file.write("\t\t\tchild = Node.Node(value, tempDict[value])\n")
    file.write("\t\t\tresult = tempDict[value]\n")
    file.write("\t\t\ttempDict = tempDict[value]\n")
    #otherwise, break
    file.write("\t\telse:\n")
    file.write("\t\t\tprint \"can't process input %s\" % count\n")
    file.write("\t\t\tresult = \"NO\"\n")
    file.write("\t\t\tbreak\n")
    #print solutions 
    file.write("\tprint (\"entry%s = %s\" % (count, result))\n")
    #write to serial
    file.write("\tser.write(result)\n")
    file.write("\ttime.sleep(1)")
    file.write("\n\nser.close()")
    print "written program"
    
    
if __name__ == '__main__':
    main()