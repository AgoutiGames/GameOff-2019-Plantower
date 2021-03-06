import sys
destination = ""
if len(sys.argv) == 2:
    destination = sys.argv[1]
    print("Parsed class name from command line parameter")
else :
    destination = input("Please enter class name: ")

lower_dest = destination[0]
for c in destination[1:] :
    if c.isupper() :
        lower_dest += '_'
    lower_dest += c
lower_dest = lower_dest.lower()
upper_dest = lower_dest.upper()
template_h = open("template.hpp").read()
template_s = open("template.cpp").read()
dest_h = open(lower_dest + ".hpp", "w")
dest_s = open(lower_dest + ".cpp", "w")
template_h = template_h.replace("Template",destination)
template_s = template_s.replace("Template",destination)
template_h = template_h.replace("TEMPLATE",upper_dest)
template_s = template_s.replace("TEMPLATE",upper_dest)
template_h = template_h.replace("template",lower_dest)
template_s = template_s.replace("template",lower_dest)
dest_h.write(template_h)
dest_s.write(template_s)
print("Wrote class file sucessfully. Don't forget adding to CMake!")
