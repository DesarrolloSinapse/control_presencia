class AServerconfigurationsController < ApplicationController
  before_action :set_a_serverconfiguration, only: [:show, :edit, :update, :destroy]

  # GET /a_serverconfigurations
  # GET /a_serverconfigurations.json
  def index
    @a_serverconfigurations = AServerconfiguration.all
  end

  # GET /a_serverconfigurations/1
  # GET /a_serverconfigurations/1.json
  def show
  end

  # GET /a_serverconfigurations/new
  def new
    @a_serverconfiguration = AServerconfiguration.new
  end

  # GET /a_serverconfigurations/1/edit
  def edit
	
  end

  # POST /a_serverconfigurations
  # POST /a_serverconfigurations.json
  def create
    @a_serverconfiguration = AServerconfiguration.new(a_serverconfiguration_params)

    respond_to do |format|
      if @a_serverconfiguration.save
        format.html { redirect_to @a_serverconfiguration, notice: 'A serverconfiguration was successfully created.' }
        format.json { render :show, status: :created, location: @a_serverconfiguration }
      else
        format.html { render :new }
        format.json { render json: @a_serverconfiguration.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /a_serverconfigurations/1
  # PATCH/PUT /a_serverconfigurations/1.json
  def update
    respond_to do |format|
      if @a_serverconfiguration.update(a_serverconfiguration_params)
        format.html { redirect_to @a_serverconfiguration, notice: 'Device configuration was successfully updated. Next time, you have to access to new ip configuration. Rebooting device, this would take a while...' }
       format.json { render :show, status: :ok, location: @a_serverconfiguration }
	Thread.new do      
 		exec "sudo python /home/pi/Desktop/starting.py"
	end
      else
        format.html { render :edit }
        format.json { render json: @a_serverconfiguration.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /a_serverconfigurations/1
  # DELETE /a_serverconfigurations/1.json
  def destroy
    @a_serverconfiguration.destroy
    respond_to do |format|
      format.html { redirect_to a_serverconfigurations_url, notice: 'A serverconfiguration was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_a_serverconfiguration
      @a_serverconfiguration = AServerconfiguration.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def a_serverconfiguration_params
      params.require(:a_serverconfiguration).permit(:ipdevice, :networkmask, :gateway, :dns1, :url_server, :refreshtime, :refreshtime_error)
    end
end
