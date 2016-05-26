before_action :authenticate_user!

class LoginController < ApplicationController
 def index
   render text: 'You have found my secret place!'
 end
end
