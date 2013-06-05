-- Very simple script
print("Hello from Lua!!!")

arr = vector.new(cVector)
arr:reserve(50)
while arr:size() < 50 do
    arr:push_back(50)
end
print(arr:size())
