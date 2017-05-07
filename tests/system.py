##############################################################
# TEST
import lovely as love 
#OS / HW
print("os:",love.system.getOS())
print("ProcessorCount:", love.system.getProcessorCount())
#Clipboard
love.system.setClipboardText("hello")
print("Clipboard text:",love.system.getClipboardText())
#PowerInfo
t, s, p = love.system.getPowerInfo()
print("PowerInfo:",t,s,p)
##############################################################

