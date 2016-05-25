class CardsController < ApplicationController
  before_action :set_card, only: [:show, :edit, :update, :destroy]
  load_and_authorize_resource
  # GET /cards
  # GET /cards.json
  def index
    @cards = Card.order(:usuario_id)
  end

  # GET /cards/1
  # GET /cards/1.json
  def show
  end

  # GET /cards/new
  def new
    @card = Card.new
  end

  # GET /cards/1/edit
  def edit       
  end

  # POST /cards
  # POST /cards.json
  def create
    @card = Card.new(card_params)

    respond_to do |format|
      if @card.save              
        
        if !@card.usuario_id.blank?          
          u = Usuario.find(@card.usuario_id)          
          if u.card_id.nil?
            u.card_id = @card.id
            u.save
          else
            c = Card.find(u.card_id)
            c.activa = 0
            c.save
            u.card_id = @card.id
            u.save
          end
        end 

        format.html { redirect_to @card, notice: 'La tarjeta se ha creado correctamente.' }
        format.json { render :show, status: :created, location: @card }
      else
        format.html { render :new }
        format.json { render json: @card.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /cards/1
  # PATCH/PUT /cards/1.json
  def update
    respond_to do |format|
      if @card.update(card_params)
         if !@card.usuario_id.blank?          
          u = Usuario.find(@card.usuario_id)          
          if u.card_id.nil?
            u.card_id = @card.id
            u.save
          else
            c = Card.find(u.card_id)
            c.activa = 0
            c.save
            u.card_id = @card.id
            u.save
          end
        end         
        format.html { redirect_to @card, notice: 'La tarjeta se ha actualizado correctamente.' }
        format.json { render :show, status: :ok, location: @card }
      else
        format.html { render :edit }
        format.json { render json: @card.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /cards/1
  # DELETE /cards/1.json
  def destroy
    if @card.usuario_id.blank?
      @card.destroy
      respond_to do |format|
        format.html { redirect_to cards_url, notice: 'La tarjeta se ha eliminado correctamente.' }
        format.json { head :no_content }
      end
    else
      respond_to do |format|
        format.html { redirect_to cards_url, notice: 'No se puede eliminar una tarjeta asociada a un usuario.' }
        format.json { head :no_content }
      end
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_card
      @card = Card.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def card_params
      params.require(:card).permit(:id, :codigo, :usuario_id, :activa)
    end
end
