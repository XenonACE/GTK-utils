ps ax | grep '/usr/lib/bluetooth/[b]luetoothd' > /dev/null
echo $?
