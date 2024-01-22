

def show_status(status):
    if status.is_ok() and not status.error_description:
        return True
    print(f"[ERROR CODE]:  {status.error_code}, [ERROR DESCRIPTION]: {status.error_description}")
    return False


