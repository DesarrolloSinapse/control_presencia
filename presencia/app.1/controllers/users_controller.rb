class UsersController < ApplicationController

	load_and_authorize_resource

	def index
		@usuarios = User.order(:id)
		@email = Email.take
	end

	def new
		@user = User.new
	end

	def create
		@user = User.new(user_params)

		if @user.save
			redirect_to '/users'
		else
			render 'new'
		end
	end

	def show
		@usuario = User.find(params[:id])
	end

	def edit
		@user = User.find(params[:id])
	end

	def update	
		@user = User.find(params[:id])

		@user.update(user_params)
		redirect_to '/users'
	end

	def destroy
		@user = User.find(params[:id])
		@user.destroy
		redirect_to '/users'
	end

	private
		def set_user
			@user = User.find(params[:id])
		end

		def user_params
			params.require(:user).permit(:id, :email, :password, :admin, :encrypted_password)
		end
end
