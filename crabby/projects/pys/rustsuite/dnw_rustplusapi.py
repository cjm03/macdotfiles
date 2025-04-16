import asyncio
from rustplus import RustSocket, ServerDetails, EntityEvent, EntityEventPayload
import playsound
# def connect_to_server():
#     server_details = ServerDetails("45.88.228.99", "28017", "76561198182931553", "fVSfS_pyI3o:APA91bGQRnfzwZSNp7ljCauZK6kZhB0qsEX-9HqUQ4Nay37FhxKFT2M-o6Ozm6nEW2DpkruqA81sNxnSo5O9rxxy_GGCTXP7XTUCYx3v74IBU47Iv1AEPlRxHN0iZ527gGAdDscKzzyM")
#     socket = RustSocket(server_details)
#     return socket


# def main():
#     socket = connect_to_server()

async def main():
    server_details = ServerDetails("208.52.153.80", "28084", 76561198182931553, 1494665586)
    socket = RustSocket(server_details)
    await socket.connect()
    print("Connected")
    print(socket)

    @EntityEvent(server_details, 172709459)
    async def alarm(event: EntityEvent):
        value = "On" if event.value else "Off"
        print(f"Raid alarm switched {value}\nTime: {(await socket.get_time()).time}")
        playsound.playsound('fyc.mp3')

    print(await socket.get_entity_info(172709459))
    print("Hanging socket...\nSocket hung! Waiting...")
    await socket.hang()

asyncio.run(main())
