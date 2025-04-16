import asyncio
from rustplus import RustSocket, ServerDetails, EntityEvent, EntityEventPayload
from playsound import playsound

server_details = ServerDetails("208.52.153.80", "28016", 76561198182931553, 1494665586)

# @EntityEvent(server_details, 52394719)
# async def alarm(event: EntityEventPayload):
#     await event.value == True
    
#async def main():
#    server_details = ServerDetails("208.52.153.80", "28084", 76561198182931553, 1494665586)
#    socket = RustSocket(server_details)
#    await socket.connect()
#    print("Connected")
#
#    while True:
#        @EntityEvent(server_details, 172709459)
#        async def alarm(event: EntityEventPayload):
#            value = "On" if event.value else "Off"
#            print(f"Raid alarm switched {value}\nGood Luck!")
#            playsound('fyc.mp3')
#            await socket.disconnect
#        break

@EntityEvent(server_details, 172709459)
async def alarm(event: EntityEventPayload):
    value = "On" if event.value else "Off"
    print(f"Raid alarm switched {value}\nGood Luck!")
    playsound('fyc.mp3')

async def main():
    socket = RustSocket(server_details)
    await socket.connect()
    print("Connected")
    await socket.get_entity_info(172709459)
#    await socket.hang()
#    print("Socket has been hung")

    while True:
        await asyncio.sleep(1)


asyncio.run(main())
