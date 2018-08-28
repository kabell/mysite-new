def auth(request):
    if request.session.get('login',False):
        return True
    return False